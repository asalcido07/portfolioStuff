class String
    define_method(:triple_each_letter) do
        self.each_char() do |letter|
            3.times() do
                print letter
            end
        end
        puts
    end
end

"Hello".triple_each_letter()