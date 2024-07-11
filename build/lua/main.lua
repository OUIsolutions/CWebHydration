



local function main()

        local js_result = Construct_js();
        dtw.write_file(JS_CONTENT,js_result)

        local  amalgamation =  Generate_amalgamation_recursive(START_POINT)

        dtw.write_file(OUTPUT_SINGLE_FILE,amalgamation)
        Execute_tests()
        Create_examples()
       local new_readme =  Create_readme();
       dtw.write_file("README.md",new_readme)
end

main()