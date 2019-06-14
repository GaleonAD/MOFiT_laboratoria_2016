import subprocess


for Num in range(1000,100000,500):
	args = ['./RUN',str(Num)]
	subprocess.Popen(args)
