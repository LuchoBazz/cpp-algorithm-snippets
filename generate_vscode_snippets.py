import sys
import os
import json
import platform

HOME = os.path.expanduser("~") 

OS = platform.system()

if OS in ['Windows', 'Win32']: # for windows
    PATH = HOME + '/AppData/Roaming/Code/User/snippets/cpp.json'
elif OS == 'Linux': # for linux
    PATH = HOME + '/.config/Code/User/snippets/cpp.json'
elif OS == 'Darwin': # for mac os
    PATH = HOME + '/Library/Application Support/Code/User/snippets/cpp.json'
else:
    print(OS)
    sys.exit('unsupported operating system')

def add_snippets_to_vscode(root_path, filename, ext):
    path = root_path + filename + '.' + ext
    json_str = ''
    with open(PATH, 'r') as json_data:
        json_str += json_data.read()

    snippets = json.loads(json_str)
    code = []
    with open(path, 'r') as reader:
        code = reader.read().split('\n')
    
    if 'template_' in filename:
        for i in range(len(code)):
            line = code[i]
            line = line.replace(
                '`!v strftime("%B %d, %Y")`',
                '${CURRENT_MONTH_NAME} ${CURRENT_DATE}, ${CURRENT_YEAR}'
            )
            code[i] = line
    
    data = {
        'prefix': filename,
        'body': code
    }
    
    snippets[filename] = data

    snippets = json.dumps(snippets)
    snippets = json.loads(snippets)

    print('Snippet', filename, 'was generated')
    with open(PATH, 'w') as outfile:
        json.dump(snippets, outfile,  indent=4)

def main():
    basepath = './'
    
    for directory in os.listdir(basepath):
        if os.path.isdir(os.path.join(basepath, directory)):
            dir_path = basepath + directory + '/'
            for filename in os.listdir(dir_path):
                fragments = filename.split('.')
                ext = fragments.pop()
                filename = ''
                if len(fragments) > 0:
                    filename = fragments.pop()
                else:
                    continue

                if ext == 'cpp' and filename != '':
                    add_snippets_to_vscode(dir_path, filename, ext)

if __name__ == '__main__':
    main()