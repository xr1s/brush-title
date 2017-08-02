enc = 'e5534adac53023aaad55518ac42671f8a1471d94d8676ce1b11309c1c27a64b1ae1f4a' \
'91c73f2bfce74c5e8e826c27e1f74c4f8081296ff3ee4519968a6570e2aa0709c2c4687eece4' \
'4a1589903e79ece75117cec73864eebe57119c9e367fefe9530dc1'

msg = enc.scan(/.{8}/).collect do |group|
  group.scan(/../).reverse.join.hex
end

for i in (1...msg.length)
  msg[-i] ^= msg[-i - 1]
end

puts(msg.collect do |group|
    group.to_s(16).scan(/../).map(&:hex).map(&:chr).reverse.join
end.join)
