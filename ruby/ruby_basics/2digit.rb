class Fixnum
    define_method(:has_two_digits?) do
        if self.>10 and self.<99
            true
        elsif self.<(-10) and self.<(-99)
            true
        else
            false
        end
    end
end

puts 10.has_two_digits?()

puts -4.has_two_digits?()