import sys

def solve():
    def get_ints():
        leftover = ""
        while True:
            chunk = sys.stdin.read(262144)
            if not chunk:
                break
            if leftover:
                chunk = leftover + chunk
            
            if chunk[-1].isspace():
                tokens = chunk.split()
                leftover = ""
            else:
                tokens = chunk.split()
                if tokens:
                    leftover = tokens.pop()
                else:
                    leftover = ""
                    
            for t in tokens:
                yield int(t)
        if leftover:
            yield int(leftover)

    tokens = get_ints()
    
    try:
        c = next(tokens)
    except StopIteration:
        return

    MAX_P = 1000005
    is_prime = bytearray(b'\x01' * MAX_P)
    is_prime[0] = 0
    is_prime[1] = 0
    for i in range(2, int(MAX_P**0.5) + 1):
        if is_prime[i]:
            is_prime[i*i : MAX_P : i] = bytes(len(range(i*i, MAX_P, i)))

    primes_count = 0
    pos = 1
    
    try:
        prev_val = next(tokens)
    except StopIteration:
        return
        
    if prev_val < MAX_P:
        if is_prime[prev_val]:
            primes_count += 1
    else:
        if prev_val % 2 != 0 and prev_val % 3 != 0:
            pf = True
            for i in range(5, int(prev_val**0.5) + 1, 6):
                if prev_val % i == 0 or prev_val % (i + 2) == 0:
                    pf = False
                    break
            if pf:
                primes_count += 1
                
    drop_found = False
    
    for val in tokens:
        pos += 1
        if val < prev_val:
            drop_found = True
            break
            
        if val < MAX_P:
            if is_prime[val]:
                primes_count += 1
        else:
            if val % 2 != 0 and val % 3 != 0:
                pf = True
                for i in range(5, int(val**0.5) + 1, 6):
                    if val % i == 0 or val % (i + 2) == 0:
                        pf = False
                        break
                if pf:
                    primes_count += 1
                    
        prev_val = val
        
    if not drop_found:
        pos = 1
        primes_count = 0
        
    print(f"{pos} {primes_count}")

if __name__ == '__main__':
    solve()
