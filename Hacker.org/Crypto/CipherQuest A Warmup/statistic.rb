enc = 'tulgqBmqBvuqbdhpslBtuclBmpBjpBfuzclstBjgsCBuztBxhtjBmpBvpfgzepBjpBbpct' \
'BdpgccqBehfk.BhBxpstBtuBjheBjuzepBgsqxgqBtuBezdodhepBjhmBxhtjBjumpmglpBeuzo.' \
'BhBxgckBhsBtuBjheBduumBuscqBtuBbhslBjhmBjuukhsCBzoBxhtjBmqBehetpd.BejpBfgstB' \
'ldhap.BuzdBmumBlduapBjpdBtjpdp.Bbmc'

statistic = { }

enc.each_char do |char|
    char = char.to_sym
    if statistic[char]
        statistic[char] += 1
    else
        statistic[char] = 1
    end
end

puts statistic

puts enc.tr 'tulgqBmqBvuqbdhpslBtuclBmpBjpBfuzclstBjgsCBuztBxhtjBmpBvpfgzepBjpBbpctBdpgccqBehfk.', 'today my boyfriend told me he couldnt hang out with me because he felt really sick.'

puts 'SOLUTION: '

puts enc.tr('tulgqBmqBvuqbdhpslBtuclBmpBjpBfuzclstBjgsCBuztBxhtjBmpBvpfgzepBjpBbpctBdpgccqBehfk.', 'today my boyfriend told me he couldnt hang out with me because he felt really sick.')[0, 25]
