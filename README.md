# `daemontools`

`daemontools` is a collection of tools by [D.J. Bernstein](http://cr.yp.to/daemontools.html) for managing UNIX services. It monitors `qmail` services and saves error messages to one or more logs.

## `multilog` program with human readable datetime
The `multilog` program has been modified to work both with timestamps and human readable datetimes ([commit](https://github.com/sagredo-dev/daemontools/commit/80f213303646419ddfbfe412df21741d5ee2abfd))

- the action `t` inserts an @, a precise timestamp, and a space in front of each line, using the same format as `tai64n`.

Example: 

`multilog t '-*' '+* fatal: *' ./main`

prints the line

`@400000003b4a39c23294b13c fatal: out of memory`

- the action `d` inserts a human readable datetime in front of each line.

Example:

`multilog d '-*' '+* fatal: *' ./main`

prints the line

`2024-07-29 10:36:08.811661123 fatal: out of memory`

Both flags are required to be the first action.

## Other patches applied
Patches applied to the [original djb daemontools-0.76](http://cr.yp.to/daemontools.html):

* [errno patch](https://github.com/sagredo-dev/daemontools/commit/eb422979a852c341ca32096fff6d894fb486a222)
* [multilog_filesize_limit patch](https://github.com/sagredo-dev/daemontools/commit/48b7393aafaccb4082a0707b1388b2bc0dd1003b) by Sam Tang, which extends the file log size limit to 100MB (default is 16MB).

## More info and support
You can find more info and ask for support at https://notes.sagredo.eu/en/qmail-notes-185/daemontools-14.html

Post any comment there.
