class Fixnum
    define_method(:absolutely_larger) do
        if self.>(0)
            self.+(1)
        elsif self.<(0)
            self.(1)
        end
    end
end

puts 7.absolutely_larger()

puts -(4).absolutely_larger()