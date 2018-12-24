import multiprocessing, time, os

def func1():
	print('process name: func1','process id:',os.getpid())
	time.sleep(2)
	print("End of func1")

def func2():
	print('process name: func2','process id:',os.getpid())
	time.sleep(3)
	print("End of func2")

def func3():
	print('process name: func3','process id:',os.getpid())
	print('Number of processes started are:', len(processes)+1)
	time.sleep(4)
	print("End of func3")

processes = [ ]

p = multiprocessing.Process(target=func1)
processes.append(p)
p.start()

p = multiprocessing.Process(target=func2)
processes.append(p)
p.start()

p = multiprocessing.Process(target=func3)
processes.append(p)
p.start()

i = 0
while i<len(processes):
	processes[i].join()
	i += 1

print("End of Program!")
