

# run this program quine.py >> quine.c
header = "\t0\n};\n\n"
d = header + open("quine.c").read()
for c in d:
  print("\t%s," % repr(c))
print("\t0")