enc = 'xqfBprtAodflyrAofABhozxoldBdriadBtqozqBqiyyvgABzvaafABxqfxvpdBtfgfByar' \
'tpBopxrBxqfBvogByjBxqfByavdxmBxqfjBtfgfBzvnxigfAByjBcfpidBwrgzfdBidopkBvpBfa' \
'fzxgrpozBgoyyrpBvpABdizsfABopxrBhvziilBurpfdBvgripABxqfBtrgaAmBxqfBqipAgfAdB' \
'rwByoaaorpdBrwBzvnxigfABxqfxvpdBtfgfBxvsfpBxrBvBxjnfBrwBzopflvBtqfgfBxqfjBtf' \
'gfBwrgzfABxrBtvxzqBvBxqgffABdinfgBzrarddvaBlrxorpBnozxigfBwrgBxqogxjdocBAvjd' \
'mBxqodBolnavpxfABtqvxBqiyyvgABxfglfABhvgoridBlodafvAopkBAvxvBopxrBxqfBlflrgo' \
'fdBrwBxqfBqvnafddBxqfxvpdBtqozqBqvdBxrBArBtoxqBkrABxqfBAfhoaBdnvzfBrnfgvBfxB' \
'zfxfgvmBxqodBopzaiAfABvaaBtrgaABgfaokorpdBtoxqBqiyyvgABdnfzowozvaajBvxxgoyix' \
'opkBgrlvpBzvxqraozodlBvpABxqfBolvkfBrwBxqfBzgizowocorpBxrBxqfBopwaifpzfBrwBc' \
'fpimBxqfBxtrBolnavpxBdxvxorpdBzoxfAByjBqiyyvgABtfgfBdvoABxrBqvhfByffpBarzvxf' \
'ABrpBqvtvooBvpABavdBnvalvdBopBxqfBzvpvgjBodavpAdmBopBvAAoxorpBxrBolnavpxopkB' \
'pftByfaofwdBopBxqfBxqfxvpdBxqfBolvkfdBAfngohfABxqflBrwBxqfogBdfpdfBrwBnfgdrp' \
'vaBoAfpxoxjmBtqfpBxqfBxqfxvpdBafwxBxqfBngrefzxorpBvgfvdBxqfjBdxvgxfABxrBzaid' \
'xfgBxrkfxqfgBopBkgrindBrwBvBwftBxqridvpABqvhopkBardxBxqfBvyoaoxjBxrBAowwfgfp' \
'xovxfByfxtffpBfvzqBrxqfgmBfvzqBzaidxfgBrwBxqfxvpdBkvxqfgfABopxrBrpfBrwBxqfBw' \
'ftBgflvopopkByrAofdBxqvxBdighohfABxqfBfcnardorpmBxqfdfByfzvlfBtqvxBvgfBsprtp' \
'BvdByrAjBxqfxvpdBtqozqBvgfBdvoABxrByfBdxoaaBzaopkopkBxrBvpABvAhfgdfajBvwwfzx' \
'opkBfhfgjrpfBfczfnxBxqrdfBdzofpxrarkodxdBtqrBqvhfBnfgwrglfABxqfBpfzfddvgjBdx' \
'fndBxrBgflrhfBxqflm'

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

puts enc.tr 'BfxvorpqdgAazitywlnkjhmcsue', ' etaionhsrdlcuwbfmpgyv.xkue'
