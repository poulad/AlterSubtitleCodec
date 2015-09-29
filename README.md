## AlterSubtitleCodec
Many subtitle files have various encodings and most of video players have difficulties with reading subtitles which are not in not in UTF-8 format.
**AlterSubtitleCodec** is a solution to that issue. It changes the given file's encoding to UTF-8.

Usage: altersubtitlecodec [input] [codec] [output]

*for example: altersubtitlecodec movie-fa.srt windows-1256 movie-fa-utf8.srt*

Program asks user the encoding the file has and writes a new file in UTF-8 encoding using the input file.
list of all supported encoding is avalable at [iana.org](https://www.iana.org/assignments/character-sets/character-sets.xhtml)
