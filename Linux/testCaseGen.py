import random
import string

s='abcdefghijklmnopqrstuvwqyz !@#$%^&*';
r1=r2=r3=''
for i in range(random.randint(1,10)):
	r1+=s[random.randint(0,len(s)-1)]
for i in range(random.randint(1,10)):
	r2+=s[random.randint(0,len(s)-1)]
domains=['com','org','us','gov','net','edu']
if random.randint(0,1):
	r3=domains[random.randint(0,len(domains)-1)]
else:
	for i in range(random.randint(1,4)):
		r3+=s[random.randint(0,len(s)-1)]
print(r1+'@'+r2+'.'+r3)
