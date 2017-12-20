import pygame 
import pygame.mixer
from pygame import Surface
import sys
import time # for sleep
from subprocess import call
import socket, pickle
import threading
import re

call(["./sevenseg", "0"])
call(["./ledset1", "7", "7"])

pygame.font.init()
pygame.display.init()
#pygame.mixer.init()
#soundc= pygame.mixer.Sound("c+_tone.ogg")
#sounde= pygame.mixer.Sound("e_tone.ogg")
#soundg= pygame.mixer.Sound("g_tone.ogg")
#soundchi = pygame.mixer.Sound("c_tone.ogg")

screen = pygame.display.set_mode((800,480))

red = (255,0,0)
green = (0,255,0)
white = (255,255,255)
blue = (0,0,255)
yellow = (255,255,0)

g_x = 0
g_y = 0
y_x = 0
y_y = 240
r_x = 400
r_y = 0
b_x = 400
b_y = 240
HEIGHT = 240
WIDTH = 400

def redraw():
	pygame.draw.rect(screen, green, (g_x,g_y,WIDTH,HEIGHT), 0)
	pygame.draw.rect(screen, yellow, (y_x,y_y,WIDTH,HEIGHT), 0)
	pygame.draw.rect(screen, red, (r_x,r_y,WIDTH,HEIGHT), 0)
	pygame.draw.rect(screen, blue, (b_x,b_y,WIDTH,HEIGHT), 0)

	pygame.display.update()
	
	
def checkColor(x, y):
	
	if (x <= 400):
		if(y <= 240):
			#soundc.play()
			flash(0)
			return 0
		else:
			#sounde.play()
			flash(1)
			return 1
	else:
		if(y <= 240):
			#soundg.play()
			flash(2)
			return 2
		else: 
			#soundchi.play()
			flash(3)
			return 3
			

def flash(num):
	if(num == 0):
		x = g_x
		y = g_y
		color = green
	elif(num == 1):
		x = y_x
		y = y_y
		color = yellow
	elif(num == 2):
		x = r_x
		y = r_y
		color = red
	elif(num == 3):
		x = b_x
		y = b_y
		color = blue
	pygame.draw.rect(screen, white, (x,y,WIDTH,HEIGHT), 0)
	pygame.display.update()
	time.sleep(0.1)
	pygame.draw.rect(screen, color, (x,y,WIDTH,HEIGHT), 0)	
	pygame.display.update()
		
def clientSend(message):
	# Create a TCP/IP socket
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
	# Connect the socket to the port where the server is listening
	server_address = ('131.128.51.97', 2345)
	print >>sys.stderr, 'connecting to the %s port %s' % server_address
	sock.connect(server_address)
	try:
		# Send data
		print >>sys.stderr, 'sending "%s"' % message
		sock.send(message)
	except(KeyboardInterrupt):
		quit()
	finally:
		print >>sys.stderr, 'closing socket'
		sock.close()
	
	
def gameOver():
	global lives, oplives
	print "Game Over"
	call(["./ledset1", ledvals[lives], opledvals[oplives]])	
	myfont = pygame.font.SysFont("Comic Sans", 72)
	label = myfont.render("Game Over!", 1, (0,0,0))
	screen.blit(label, (260, 210))
	pygame.display.update()
	time.sleep(2)
	redraw()
	if (lives == 0):
		centerText("LOSER!")
	else:
		centerText("WINNER!")
	quit()	
	
	
def play():
	global counter #reference the global var counter, bc we don't want to reset it
	global seqData
	global seq1
	global seq2
	global lock
	
	seq1 = []	#seq1 is initialized empty
	
	#Get sequence input from user
	while len(seq1) < rounds:
		for event in pygame.event.get():
			if (event.type == pygame.QUIT):
				quit()
			if event.type == pygame.MOUSEBUTTONUP:
				x, y = event.pos
				seq1.append(checkColor(x, y))
		
	#if there is a previous sequence, check to see if correct
	if(rounds > 1):
		temp = seq1
		temp = temp[:-1]
		if(seq2 != temp):
			lose()	#if they don't match, this player loses
			seq1 = []
			seq2 = []
			return seq1, seq2
			
	#dump seq1 to byte stream and send to opponent
	temp = pickle.dumps(seq1)
	clientSend(temp)
	
	#Do server stuff
	with lock:
		# Create a TCP/IP socket
		sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
		# Bind the socket to the port
		server_address = ('131.128.51.112', 1234)
		print >>sys.stderr, 'starting up on %s port %s' % server_address
		sock.bind(server_address)
		# Listen for incoming connections
		sock.listen(1)
	
		while True:
			try:
				# Wait for a connection
				print >>sys.stderr, 'waiting for a connection'
				connection, client_address = sock.accept()
			except(KeyboardInterrupt):
				quit()
			try:
				print >>sys.stderr, 'connection from', client_address
				# Receive the data in small chuncks and retransmit it
				while True:
					data = connection.recv(100)
				
					#flag = True	# this tests if data has been received
					if data:
						print >>sys.stderr, 'received the data %s' % data
						seqData.append(data)
					else:
						print >>sys.stderr, 'no more data from', client_address
						break
			finally:
				# Clean up the connection
				flag = True
				connection.shutdown(socket.SHUT_RDWR)
				connection.close()
			break	
	
	with lock:
			#print "in lock loop"
			for event in pygame.event.get():
				if (event.type == pygame.QUIT):
					sthread.exit()
					quit()
					
	result = pickle.loads(seqData[counter])
	
	#Check if opponent's sequence is wrong
	if (result != seq1):
		win()
		seq1 = []
		seq2 = []
		return seq1, seq2
	
	#Flash opponent's sequence
	for index in range (len(seq1)):
		time.sleep(0.5)
		flash(seq1[index])
	
	return seq1, seq2
	
		
	
def lose():
	global lives, rounds, seqData, counter, outcome
	rounds = 0
	clientSend("XXX")
	lives = lives - 1
	call(["./ledset1", ledvals[lives], opledvals[oplives]])
	centerText("You Lose!")
	seqData = []
	counter = 0
	outcome = True

def win():
	global rounds, seqData, counter, outcome, oplives
	rounds = 0
	oplives = oplives - 1
	call(["./ledset1", ledvals[lives], opledvals[oplives]])
	seqData = []
	counter = 0
	centerText("You Win!")
	outcome = True
	
def centerText(text):
	myfont = pygame.font.SysFont("Comic Sans", 72)
	label = myfont.render(text, 1, (0,0,0))
	screen.blit(label, (260, 210))
	pygame.display.update()
	time.sleep(2)		
	redraw()
	
	
	
seq1 = []
seq2 = []	
seqData = []
lock = threading.Lock()
lives = 3
oplives = 3
counter = 0
rounds = 0
outcome = False
ledvals = ["0", "1", "3", "7"]
opledvals = ["0", "4", "6", "7"]
redraw()
while (lives > 0 and oplives > 0):
	rounds = rounds + 1
	call(["./sevenseg", str(rounds)])
	play()
	if (outcome != True):
		temp = seq2
		seq2 = seq1
		seq1 = temp
		counter = counter + 1
	else:
		outcome = False
		if (lives > 0 and oplives > 0):
			centerText("New Round!")
gameOver()
	
	
