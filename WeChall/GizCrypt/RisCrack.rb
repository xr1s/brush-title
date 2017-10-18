alphabet = ('a'..'z').to_a + ('A'..'Z').to_a
digits = ('0'..'9').to_a
punctuation = ["\n", ' ', '!', '"', ',', '.', ':', '?']
charset = digits + alphabet + punctuation

cipher = '''
64 74 7A 59 6B 3A 36 5B 7E 37 72 49 73 69 65 2A
6D 45 5E 73 37 55 6B 7F 0C 77 73 49 36 4D 70 40
6F 0C 63 43 21 5E 74 77 51 24 62 7E 7B 79 37 75
49 6E 70 38 2A 55 44 5C 65 37 45 77 2A 4D 7B 60
56 7F 42 75 0D 2A 65 63 0C 76 43 64 7A 51 24 74
73 32 69 78 6E 40 36 6D 70 2A 78 43 40 36 74 4D
6A 2A 40 73 60 5A 73 0C 73 0C 67 49 64 5F 60 4B
74 36 5C 6A 36 62 7A 6F 37 72 43 7A 71 62 63 6E
42 15 70 78 5E 71 67 5F 3A 21 58 73 40 7E 45 64
4B 37 59 72 0C 79 79 42 24 6F 79 67 2A 64 6E 40
60 61 72 2A 68 58 1B 36 58 44 28 2A 65 36 60 40
7B 43 61 58 2A 4A 78 5E 66 43 65 36 41 6B 36 62
77 66 7B 21 55 79 71 36 7E 69 49 15 66 76 5F 77
7D 43 64 65 16 36 6D 27 1A 32 14 2E 6E 30 1B 29
57 74 2A 36 5F 7C 2A 74 60 5F 73 24 6F 65 74 0C
54 64 72 0C 77 7E 45 7A 6D 0C 62 5E 6B 45 64 4B
37 4D 6F 48 31 7E 54 72 73 36 7C 65 37 6D 59 75
6F 3A 2A 78 43 40 36 7A 4D 7D 68 49 36 6F 49 73
48 32 5F 65 41 72 0C 6C 43 63 73 15 67 7F 66 7A
6F 65 75 49 6E 70 38 2A 55 44 5C 65 37 45 77 2A
58 7E 64 0C 73 42 76 0C 65 4A 37 58 69 49 31 7B
50 77 65 77 75 6F 39 '''.split.map do |byte| byte = byte.to_i(16) end

klen = 11
k = -1
x = 1

xor = [[], [], [], [], [], [], [], [], [], [], []]
key = [[], [], [], [], [], [], [], [], [], [], []]
cipher.each do |byte|
  if (k += x) >= klen
    x = 1 if (x += 1) == klen
    k = 0
  end
  xor[k] << byte
end

(0...11).each do |index|
  alphabet.each do |char|
    key[index] << char if xor[index].collect do |byte|
      charset.include? (byte ^ char.ord ^ 'e'.ord).chr
    end.reduce:&
  end
end

key.each do |possible| p possible end

puts 'Obviously, the key is "ItsPassword"'
key = 'ItsPassword'.bytes
p key

k = -1
x = 1
cipher.each do |byte|
  if (k += x) >= klen
    x = 1 if (x += 1) == klen
    k = 0
  end
  print (byte ^ key[k] ^ 'e'.ord).chr
end
