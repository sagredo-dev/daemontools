# daemontools
My patched daemontools

Patches applied to the original daemontools-0.76:

* errno patch
* multilog_filesize_limit patch by Sam Tang, which extends the file log size limit to 100MB (default is 16MB).
* My multilog-readable_datetime patch, which replaces the timestamp with a human readable datetime.

You can find the patches applied in the src/patches directory.
More info at https://notes.sagredo.eu/en/qmail-notes-185/daemontools-14.html
Post any comment there.

Original daemontools-0.76 program by DJB here http://cr.yp.to/daemontools.html
