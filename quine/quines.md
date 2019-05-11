# Quines

A quine is a program that prints its own src code.

The quine bootstrap program is the start point to start the quine, to generate
the quine run `cp quine_bootstrap.c quine.c && python3 quine.py >> quine.c`.
This appends the contents of the `s` array to `quine.c`.

Now:
- Commpile quine to produce quine1: `gcc -o quine1 quine.c`
- run `quine1` to produce `quine2.c`: `quine1 > quine2.c`
- Compile `quine2.c` to produce `quine2.c`: `gcc -o quine2 quine2.c`
- Run `quine2` to produce `quine3.c` which should be an exact copy of `quine2.c`

The quine works because the `s` array contains a representation of the program,
starting at the `0` termintaor, which is the header insterted by the python
script, through to the end of the program. The program itself prints the
definition of the `s` array then loops through each character in `s` up to, but
not including the `0`, printing its representation (`"\t%d,\n"`)