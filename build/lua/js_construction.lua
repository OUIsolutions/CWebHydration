

function Construct_js()
    local all = ""
	local listage,size = dtw.list_files_recursively(JS_FOLDER,true)
	for i=1,size do
	    local content = listage[i]
		all = all.."\n"..dtw.load_file(content)
	end
	local in_hexa = clib.to_hexa(all)
    local formmated = 'const char * JS_CONTENT = "'..in_hexa..'";'
    return formmated
end