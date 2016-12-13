import re

myStr = raw_input().encode('string-escape')
line = re.sub("[\[!,?\.\\\\_'@\]\+]", ' ',myStr)
#line = re.split('(\W+)', myStr)
 
#line = re.findall("(\[!,?\.\\_'@\]\+)", ' ',line)
line = line.split()
print len(line)
for w in line:
    print w
"""
while "'" or "[" or "!" or "," or "?" or "." or "\\" or "_" or "@" or"]" or "+" in myStr:
    myStr.pop(myStr.index("'")))
else:
    print 'nop'

print myStr
"""
