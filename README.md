OOP.String
==========

Cool String type concepts and tips for low level entertainers 🥸

> [!WARNING]
>
> This program was builtin my `Void Linux x86_64` + compiled with
> [`gcc`](https://gcc.gnu.org/) 14.2.1 and
> [`gnu make`](https://www.gnu.org/software/make/) 4.4.1. If you
> don't have these tools, I can't guarantee that everything will work
> fine!

## What's that?

A little while ago, I was thinking about what it would be like to
develop a programming language (compiled or interpreted) and I spent
a lot of time thinking about `Strings` 🤔

Things like `'\0'` terminator, diffs between `char []` and `char *`.
Update object fields during changing/reading meaning values...

So, I take a time to study and share knowledge about
`C lang Strings` 🔗

### Sources

About **sources**, there's three related dirs:
1. **core**: core utilities used amoung the entire program (C/Headers)
2. **headers**: header definitions destinated for each C source
3. **src**: well, the source (C file implementations)

### Compiling

There's also a Makefile script which you can use to build the
binaries. In the Makefile you can use the `build` and `clean`
subcommands as well as they alias (`b` and `c`, respectively).

### Running

There's not a `run` in the Makefile. Each source file will produce it
own binary that should be runned indenpendently from other binaries.

By default, they'll be droped at **out/** dir and should be runned
like:
```sh
out/<BIN_NAME> (MAYBE A SUBCOMMAND)
```
