import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import os

lang_dict = {
    'nim': 'Nim',
    'go' : 'Go',
    'js' : 'Node.js',
    'rs' : 'Rust',
    'py' : 'Python',
    'cpp': 'C++',
    'c'  : 'C',
    'jl' : 'Julia',
    'txt': 'Text'
}

def func(pct, data):
    val = int(np.round(pct/100.*np.sum(list(data.values()))))
    key = list(data.keys())[list(data.values()).index(val)]
    return "{:.1f} %\n({})".format(pct, data[key])

def plot_save(dictionary, path):
    plt.figure(figsize=(6,6))
    plt.pie(
        x=dictionary.values(),
        labels=dictionary.keys(),
        colors=sns.color_palette('colorblind'),
        autopct=lambda pct: func(pct, dictionary),
        pctdistance=0.75
        )
    plt.savefig(path, format='png')

total_len_dict = {}

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
            del len_dict['Text']
            len_dict = {k: v for k, v in sorted(
                len_dict.items(), key=lambda item: item[1], reverse=True)
                }
            total_len_dict.update(len_dict)
            print(len_dict)
            plot_save(len_dict, os.path.join(year, day, 'plot.png'))
            print()
print()
print(total_len_dict)
plot_save(total_len_dict, "./total.png")