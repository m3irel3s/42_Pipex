#GDB Settings
set print pretty on
set print array on

set style enabled on


set logging enabled on

define main
	disp *argv@argc
end

define get_path

end

fs cmd
file pipex
break main
break get_path
run ./pipex "ls -l"

info break
info watch