# https://api.github.com/search/repositories?q=opendaylight
# https://api.github.com/search/repositories?q=topic:opendaylight

# get_names -- check_repos
import requests


def get_names():
    print('Separate each name with Space:')
    names = input()
    return names.split()


def check_repos(names):
    repo_api = 'https://api.github.com/search/repositories?q='
    ecosys_api = 'https://api.github.com/search/repositories?q=topic:'
    for name in names:
        repo_info = requests.get(repo_api + name).json()['items'][0]
        # json - dict - dict['items'] - list[0]
        stars = repo_info['stargazers_count']
        forks = repo_info['forks_count']
        ecosys_info = requests.get(ecosys_api + name).json()['total_count']

        print(name)
        print('Stars: ' + str(stars))
        print('Forks: '+ str(forks))
        print('Ecosys: ' + str(ecosys_info))
        print('----------------------')
    return


names = get_names()
check_repos(names)
