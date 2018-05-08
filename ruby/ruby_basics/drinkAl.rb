class Fixnum
    define_method(:can_drink_alcohol) do
        if self.<=(21)
            puts "Can drink alcohol"
        else
            puts "Can't drink alcohol"
        end
    end
end

24.can_drink_alcohol()

14.can_drink_alcohol()