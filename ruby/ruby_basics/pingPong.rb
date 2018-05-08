class Fixnum
    define_method(:ping_pong) do
        arr = []
        (self.+(1)).times() do |numOfTimes|
            if (numOfTimes.%(3) == 0 and numOfTimes.%(5) == 0)
                arr.push("ping-pong")
            elsif (numOfTimes.%(3) == 0)
                arr.push("ping")
            elsif (numOfTimes.%(5) == 0)
                arr.push("pong")
            else
                arr.push(numOfTimes)
            end
        end
        puts arr
    end
end

33.ping_pong();

=begin
##########################
ping-pong
1
2
ping
4
pong
ping
7
8
ping
pong
11
ping
13
14
ping-pong
16
17
ping
19
pong
ping
22
23
ping
pong
26
ping
28
29
ping-pong
31
32
ping
##########################
=end