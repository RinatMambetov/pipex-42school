# system
# < infile ls -l | wc -l > outfile
# < infile lss -l | wc -l > outfile
# < infile grep a1 | wc -w > outfile
# grep a1 << stop | wc -w >> outfile

# short_path
# ./pipex infile "ls -l" "wc -l" outfile
# leaks --atExit -- ./pipex infile "ls -l" "wc -l" outfile
# ./pipex infile "grep a1" "wc -w" outfile
# leaks --atExit -- ./pipex infile "grep a1" "wc -w" outfile
# ./pipex_bonus infile "grep a1" "wc -w" outfile
# leaks --atExit -- ./pipex_bonus infile "grep a1" "wc -w" outfile

# here_doc
# ./pipex_bonus here_doc stop "grep a1" "wc -w" outfile
# ./pipex_bonus here_doc stop "grepp a1" "wc -w" outfile
# leaks --atExit -- ./pipex_bonus here_doc stop "grep a1" "wc -w" outfile
# leaks --atExit -- ./pipex_bonus here_doc stop "grepp a1" "wc -w" outfile

# long_path
# ./pipex infile "/bin/ls -l" "/usr/bin/wc -l" outfile
# leaks --atExit -- ./pipex infile "/bin/ls -l" "/usr/bin/wc -l" outfile
# ./pipex infile "/usr/bin/grep a1" "/usr/bin/wc -w" outfile
# leaks --atExit -- ./pipex infile "/usr/bin/grep a1" "/usr/bin/wc -w" outfile
# ./pipex_bonus infile "/usr/bin/grep a1" "/usr/bin/wc -w" outfile
# leaks --atExit -- ./pipex_bonus infile "/usr/bin/grep a1" "/usr/bin/wc -w" outfile

# wrong first cmd
# ./pipex infile "lss -l" "ls -l" outfile
# ./pipex_bonus infile "lss -l" "ls -l" outfile
# ./pipex infile "lss -l" "wc -l" outfile
# ./pipex_bonus infile "lss -l" "wc -l" outfile
# ./pipex infile "/bin/lss -l" "/bin/ls -l" outfile
# ./pipex_bonus infile "/bin/lss -l" "/bin/ls -l" outfile
# leaks --atExit -- ./pipex infile "lss -l" "ls -l" outfile
# leaks --atExit -- ./pipex_bonus infile "lss -l" "ls -l" outfile
# leaks --atExit -- ./pipex infile "lss -l" "wc -l" outfile
# leaks --atExit -- ./pipex_bonus infile "lss -l" "wc -l" outfile
# leaks --atExit -- ./pipex infile "/bin/lss -l" "/bin/ls -l" outfile
# leaks --atExit -- ./pipex_bonus infile "/bin/lss -l" "/bin/ls -l" outfile
