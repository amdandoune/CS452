#Group1: Abderrahman Dandoune, Abdoul Diallo, Nishal Kayharee

from sys import argv 
import os

script, file, fileBackup = argv

print(f"Copying from {file} to {fileBackup}")

try:
	f = open(file,'r')
except IOError:
	print("Could not open file.")
	sys.exit()

l = f.readlines()

try:
	f.close()
except IOError:
    print("Could not close file.")
    sys.exit()

try:
	fd = open(fileBackup, 'w')
except IOError:
	print("Could not open file.")
	sys.exit()
fd.writelines(l)
try:
	fd.close()
except IOError:
    print("Could not close file.")
    sys.exit() 

print(f"Copying from {file} to {fileBackup} is Done.")
