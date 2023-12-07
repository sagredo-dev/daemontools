# daemontools
My patched daemontools

Patches applied to original daemontools-0.76:

* errno patch
* multilog_filesize_limit patch by Sam Tang, which extends the file log size limit to 100MB (default is 16MB).
* My multilog-readable_datetime patch, which replaces the timestamp with a human readable datetime.

More info at https://notes.sagredo.eu/en/qmail-notes-185/daemontools-14.html
