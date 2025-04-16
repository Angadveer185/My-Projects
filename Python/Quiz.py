import time

score=(0)
print("Welcome to the Quiz!!")

time.sleep(1)

print("Question 1:- What is 827 X 76?")
a = "(a) 62,852"
b = "(b) 82,762"
c = "(c) 76,827"
d = "(d) 61,652"

time.sleep(1)

print(a)
print(b)
print(c)
print(d)

time.sleep(1)

ans1 = input("Enter your answer:- ")
if ans1 == "a":
   print("Correct, good job!")
   score+=1
else:
   print("Incorrect")

time.sleep(3)

#-------------------------------------------------------------------

print("Question 2:- A car travels a distance of 240 kilometers in 3 hours. What is the average speed of the car?")
e = "(a) 60 km/h"
f = "(b) 80 km/h"
g = "(c) 120 km/h"
h = "(d) 240 km/h"

time.sleep(1)

print(e)
print(f)
print(g)
print(h)

time.sleep(1)

ans2 = input("Enter your answer:- ")
if ans2 == "b":
   print("Correct, good job!")
   score+=1
else:
   print("Incorrect")

time.sleep(3)

#-------------------------------------------------------------------

print("Question 3:- Which of the following is the slope-intercept form of a linear equation?")
i = "(a) y = mx + b"
j = "(b) x = a + by"
k = "(c) y = ax^2 + bx + c"
l = "(d) y = a/(x - h) + k"

time.sleep(1)

print(i)
print(j)
print(k)
print(l)

time.sleep(1)

ans3 = input("Enter your answer:- ")
if ans3 == "a":
   print("Correct, good job!")
   score+=1
else:
   print("Incorrect")

time.sleep(3)

#-------------------------------------------------------------------

print("Question 4:- Which of the following elements is the most reactive metal?")
m = "(a) Iron"
n = "(b) Calcium"
o = "(c) Aluminum"
p = "(d) Sodium"

time.sleep(1)

print(m)
print(n)
print(o)
print(p)

time.sleep(1)

ans4 = input("Enter your answer:- ")
if ans4 == "d":
   print("Correct, good job!")
   score+=1
else:
   print("Incorrect")

time.sleep(3)

#-------------------------------------------------------------------

print("Question 5:- Which of the following trigonometric functions represents the ratio of the side adjacent to an angle to the hypotenuse of a right-angled triangle?")
q = "(a) sine"
r = "(b) tangent"
s = "(c) cosine"
t = "(d) cosecant"

time.sleep(1)

print(q)
print(r)
print(s)
print(t)

time.sleep(1)

ans5 = input("Enter your answer:- ")
if ans5 == "c":
   print("Correct, good job!")
   score+=1
else:
   print("Incorrect")

time.sleep(3)

#-------------------------------------------------------------------

print("Question 6:- Which of the following statements is true about the atomic number of an element?")
u = "(a) It represents the number of protons in the nucleus of an atom of the element."
v = "(b) It represents the number of electrons in the nucleus of an atom of the element."
w = "(c) It represents the number of neutrons in the nucleus of an atom of the element."
x = "(d) It represents the total number of particles in the nucleus of an atom of the element."

time.sleep(1)

print(u)
print(v)
print(w)
print(x)

time.sleep(1)

ans6 = input("Enter your answer:- ")
if ans6 == "a":
   print("Correct, good job!")
   score+=1
else:
   print("Incorrect")

time.sleep(3)

#-------------------------------------------------------------------

print("Question 7:- Which of the following is true about the viscosity of a fluid?")
y = "(a) It is a measure of the fluid's ability to conduct electricity."
z = "(b) It is a measure of the fluid's refractive index."
aa = "(c) It is a measure of the fluid's buoyancy."
ab = "(d) It is a measure of the fluid's resistance to deformation under stress."

time.sleep(1)

print(y)
print(z)
print(aa)
print(ab)

time.sleep(1)

ans7 = input("Enter your answer:- ")
if ans7 == "d":
   print("Correct, good job!")
   score+=1
else:
   print("Incorrect")

time.sleep(3)

#-------------------------------------------------------------------

print("Question 8:- 20 cards are numbered from 1 to 20. If one card is drawn at random, what is the probability that the number on the card is a prime number?")
ac = "(a) 1/5"
ad = "(b) 2/5"
ae = "(c) 3/5"
af = "(d) 4/5"

time.sleep(1)

print(ac)
print(ad)
print(ae)
print(af)

time.sleep(1)

ans8 = input("Enter your answer:- ")
if ans8 == "b":
   print("Correct, good job!")
   score+=1
else:
   print("Incorrect")

time.sleep(3)

#-------------------------------------------------------------------

print("Question 9:- A well stoppered thermos flask contains some ice cubes. This is an example of")
ag = "(a) Closed system"
ah = "(b) Open system"
ai = "(c) Isolated system"
aj = "(d) Non thermodynamic system"

time.sleep(1)

print(ag)
print(ah)
print(ai)
print(aj)

time.sleep(1)

ans9 = input("Enter your answer:- ")
if ans9 == "c":
   print("Correct, good job!")
   score+=1
else:
   print("Incorrect")

time.sleep(3)

#-------------------------------------------------------------------

print("Question 10:- The range of the function f(x) = 3x-2 is")
ak = "(a) (-∞,∞)"
al = "(b) R-{3}"
am = "(c) (-∞,0)"
an = "(d) (0,–∞)"

time.sleep(1)

print(ak)
print(al)
print(am)
print(an)

time.sleep(1)

ans10 = input("Enter your answer:- ")
if ans10 == "a":
   print("Correct, good job!")
   score+=1
else:
   print("Incorrect")

time.sleep(3)

print('''the quiz has come to an end!''')
time.sleep(1)
print("Your score is:",score)