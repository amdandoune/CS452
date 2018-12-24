#Group1: Abderrahman Dandoune, Abdoul Diallo, Nishal Kayharee
import io
import os

try:
	f = open('todolist.txt','r')
except IOError:
	print("Could not open file.")
	sys.exit()
l = f.readlines()
try:
	f.close()
except IOError:
    print("Could not close file.")
    sys.exit()

l[2] = l[2].upper()
try:
	fd = open('todolist.txt', 'w')
except IOError:
	print("Could not open file.")
	sys.exit()
fd.writelines(l)
try:
	fd.close()
except IOError:
    print("Could not close file.")
    sys.exit()

os.rename('todolist.txt', "toDoList.txt" )

