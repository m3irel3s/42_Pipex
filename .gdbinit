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

define add_cmd_to_path
	disp arr[i]
	disp cmd_arr[0]
end

define handle_child_processes
	disp pid_1
	disp pid_2
end

fs cmd
file pipex
break main
break handle_child_processes

run infile "ls -l" "wc -l" outfile

info break
info watch