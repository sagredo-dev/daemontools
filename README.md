# daemontools

daemontools is a collection of tools for managing UNIX services. It monitors qmail services and saves error messages to one or more logs.

Patches applied to the [original djb daemontools-0.76](http://cr.yp.to/daemontools.html):

* errno patch
* multilog_filesize_limit patch by Sam Tang, which extends the file log size limit to 100MB (default is 16MB).
* My multilog-readable_datetime patch, which replaces the timestamp with a human readable datetime.

You can find the patches applied in the src/patches directory.
More info at https://notes.sagredo.eu/en/qmail-notes-185/daemontools-14.html

Post any comment there.
