require 'digest'

def move(tile, a, b, c)
  return '' if tile == 0
  solution = ''
  solution += move(tile - 1, a, c, b)
  solution += query(a + c)
  solution += move(tile - 1, b, a, c)
end

def query(move)
   {
      'ab' => 'we', 'ac' => 'ch', 'ba' => 'lr',
      'bc' => 'al', 'ca' => 'ul', 'cb' => 'z!',
  }[move]
end

tile = gets.chomp.to_i
solution = move tile, 'a', 'b', 'c'
puts solution
puts Digest::SHA512.hexdigest solution
