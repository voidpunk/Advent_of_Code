import matplotlib.pyplot as plt
import seaborn as sns
import os

lang_dict = {
    'nim': 'Nim',
    'go' : 'Go',
    'js' : 'JS',
    'rs' : 'Rust',
    'py' : 'Python',
    'cpp': 'C++',
    'jl' : 'Julia',
    'txt': 'Text'
}

for year in os.listdir():
    if os.path.isdir(year) and year[:2] == '20':
        for day in sorted(os.listdir(year)):
            len_dict = {}
            for program in os.listdir(os.path.join(year, day)):
                if program.endswith('png'):
                    continue
                path = os.path.join(year, day, program)
                name = lang_dict[path.split('.')[-1]]
                with open(path, 'r') as file:
                    length = len(file.read())
                len_dict[name] = length
            print(len_dict)
            del len_dict['Text']
            plt.figure(figsize=(6,6))
            plt.pie(
                x=len_dict.values(),
                labels=len_dict.keys(),
                colors=sns.color_palette('muted')
                )
            plt.savefig(os.path.join(year, day, 'plot.png'), format='png')
            print()