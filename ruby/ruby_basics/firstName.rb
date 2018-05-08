firstName = "Adam"

nameArray = []

nameArray = firstName.split("")



if ("A".."M").include?(nameArray.at(0))
    puts "Okay"
elsif ("N".."Z").include?(nameArray.at(0))
    puts "Sure"
else
    puts "Meh"
end

