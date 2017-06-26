s = 'abbbabaaabbabaaaabbaababaabaaaaaabbaaaababbabbbaabbbaabbabbbabbbabbaabababbbaabaaabaaaaaabbabaababbbaabbaabaaaaaabbaaaababbaabaaabbbabababbabbababbaaabaabbbaabaabbaaaababbbabaaabbaabab'

print(int(s.replace('a', '1').replace('b', '0'), 2).to_bytes(23, 'big'))
print(int(s.replace('a', '0').replace('b', '1'), 2).to_bytes(23, 'big'))
