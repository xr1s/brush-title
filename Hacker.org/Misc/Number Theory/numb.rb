require 'prime'

n = 36484379009457399269217182889395826722660566693989257289404709863891849615322840169192133464099837107563290320068627859223102364122264401785848633686914239718396824942863542362872670850647423969609315959515511402019435615717737240510626468808851903266920099765545245394707

factor = n.prime_division.sort do |lhs, rhs|
  lhs[1] <=> rhs[1]
end.map do |factor, id|
  factor
end

prime = Prime::first(100)
minimum = prime.index(factor.min)

factor.each do |factor|
  print (prime.index(factor) - minimum + 97).chr
end
