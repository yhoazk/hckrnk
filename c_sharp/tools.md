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

