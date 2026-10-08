from pathlib import Path
import random,subprocess
ROOT=Path(__file__).resolve().parents[1]
def run(name,data):
    binary=ROOT/name
    if not binary.exists():binary=binary.with_suffix('.exe')
    return subprocess.run([str(binary)],input=data,text=True,capture_output=True,check=True).stdout.strip()
def brute(a):
    days=0
    while True:
        survivors=[v for i,v in enumerate(a) if i==0 or a[i-1]<=v]
        if len(survivors)==len(a):return days
        days+=1;a=survivors
rng=random.Random(17)
for size in range(0,31):
    for _ in range(10):
        a=[rng.randrange(20) for _ in range(size)]
        assert int(run('mafia',str(size)+'\n'+' '.join(map(str,a))+'\n'))==brute(a),a
assert run('felix','5 4\n2 4 U\n2 4 U\n4 2 L\n4 2 L\n').splitlines()==['4','0','2','0']
assert run('felix','5 2\n5 1 U\n1 5 L\n').splitlines()==['1','1']
print('310 randomized mafia simulations and Felix edge cases passed')
