class String
    define_method(:duplicate_each_letter) do |numberOf|
        self.each_char() do |letter|
            numberOf.times() do
                print letter
            end
        end
        puts
    end
end

"Hello".duplicate_each_letter(10)