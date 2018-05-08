arr = []

4.times() do |iterator|
    3.times do 
        arr.push(iterator.+(1))
        iterator.+(1)
    end
end

print arr
