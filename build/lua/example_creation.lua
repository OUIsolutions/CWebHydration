

function Create_examples()
       dtw.remove_any(EXAMPLES_FOLDER)
	   local test_tree = dtw.newTree_from_hardware(TESTS_FOLDER)
	   test_tree.each(function (tree_part)
	        local path = tree_part.path

	        if path.get_name() ~= "exec.c" then
	        	return
	        end
            local content = tree_part.get_value()
            local formated_content = clib.replace(content,"../","")
            tree_part.set_value(formated_content)
            path.insert_dir_at_index(0,EXAMPLES_FOLDER)
            path.remove_dir_at(TESTS_FOLDER)

            tree_part.hardware_write()
            clib.print(ANSI_GREEN.."created example"..path.get_full_path().."\n")
	   end)
	   test_tree.commit()
end