

function Execute_tests()
	local files,size = dtw.list_files(TESTS_FOLDER,true)
	for i=1, size do
		local result = clib.system_with_status("gcc -Wall "..files[i]);
		if result == 0 then
			clib.print(ANSI_GREEN.."file "..files[i].." passed");
		end
		if result ~= 0 then
		    clib.print(ANSI_RED.."compilation fail")
		    clib.exit(1)
		end
	end

end