#!/usr/bin/env python

import glob, os, sys

print "GLSL Compiler"

shader_dir = sys.argv[1]



def reformat_contents(contents):
    contents = contents.replace("\n", " ").replace('"', '\"')
    return contents

def get_contents(file_name):
    with open(file_name) as f:
            contents = f.read()
            return contents
        
        
def scan_files(shader_dir):
    
    print "Looking for files in", shader_dir

    os.chdir(shader_dir)
    
    types = []
    
    shaders = {}
    
    types = ('*.vert', '*.frag') # the tuple of file types
    files_found = []
    for files in types:
     files_found.extend(glob.glob(files))

    
    for file in files_found:
        constant = "GLSL_"+file.replace('.', '_').upper()
        shaders[constant] = file
    
    return shaders
            

def save_to_header(contents):
    contents = "#ifndef GLSL_SHADERS \n#define GLSL_SHADERS\n"+contents+"#endif"
    with open("shaders.hpp", "wt") as f:
        f.write(contents)

shaders = scan_files(shader_dir)

header = ""

for s in shaders:
    path = shaders[s]
    contents = '#define '+s+' "'+ reformat_contents(get_contents(path))+'"'+"\n"
    header+=contents
    
save_to_header(header)

print "Done"
