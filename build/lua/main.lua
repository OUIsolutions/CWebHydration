



local function main()

        local js_result = Construct_js();
        dtw.write_file(JS_CONTENT,js_result)

        local  amalgamation =  Generate_amalgamation_recursive(START_POINT)

        dtw.write_file(OUTPUT_SINGLE_FILE,amalgamation)
        Execute_tests()
        Create_examples()
end

main()