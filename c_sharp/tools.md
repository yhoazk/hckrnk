# Tools

## C# Interpreter

Search for the bin `csi.exe` in the installation.
In W10 VS 2019: `C:\Program Files (x86)\Microsoft Visual Studio\2019\Preview\MSBuild\15.0\Bin\Roslyn`

Then run the live interpreter:

```cs
C:\Program Files (x86)\Microsoft Visual Studio\2019\Preview\MSBuild\15.0\Bin\Roslyn>csi.exe
Microsoft (R) Visual C# Interactive - Compilerversion 3.0.19.6812
Copyright (C) Microsoft Corporation. Alle Rechte vorbehalten.

Weitere Informationen erhalten Sie nach der Eingabe von "#help".
> Console.WriteLine("Test");
Test
>
```


## C# stand alone compiler
[src](https://docs.microsoft.com/en-us/previous-versions/ms379563(v=vs.80))

In the same path of the interactive interpreter look for the binary `csc.exe` in
`C:\Windows\Microsoft.NET\Framework\v*`.
To get an executable output use the argument `/target:exe` or to get a DLL
`/target:library`.

```cmd
C:\>type start.cs
using System;

public class Class1{
    public static void Main(){
        Console.WriteLine("Cola");
    }
}
C:\>csc.exe start.cs
C:\>start.exe
Cola
```

## XML Documenting Comments

`C#` documentation can be created by including xml elements in special comment
fields indicated by triple slashes in the source code befire the block of code.

- For single line docstrings use `///`
- For multiline delimiters use `/** */`

To enable the creation of the documentation add the option `\doc` to the 
compiler.

#### Non-comprhensive list of comment tags

- `<c>`: The text will appear formated as code
- `<para>`: Used inside a tag such as `<summary>` used to add structure to the
text
- `<code>`: same as `<c>` but in a multiline string
- `<param name="<name>">`: Should be used in the comment for a method declaration
to describe on of the parameters of the method.
- `<example>`: Multiline code to specify an example of how to use the method
- `<summary>`: Used to describe a type or a type member. This text is displayed
in by the intellisense window.
- `<exceptions cref="member">`: `member` is an exception available at compile time
the compiler checks his existence. This tag is used to document which exceptions
can be thrown from this method. 
- `<permissions cref="member">`: A `member` is a reference to a member, and should
be present at compile time. This tag is used to document the access of a member 
- `<returns>`: Used to clarify the return value of a method
- `<seealso cref="member">`: This adds the referene to the _see also_ section of the 
doc string.
- `<paramref name="<name>>`: indicates that a word used in `<summary>` block refers
to a parameter. The parser will include reference to that parameter. 
- `<remarks>`: 