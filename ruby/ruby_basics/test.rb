puts "This is main Ruby Program"

END {
    puts "Terminating Ruby Program"
}

BEGIN {
    puts "Initializing Ruby Program"
}

# I am a comment. Just ignore me.

# This is a comment

=begin
This is a comment. 
This is a comment, too.
This is a comment, too.
I said that already.
=end

class Sample
    def hello
        puts "Hello Ruby!"
    end
end

object = Sample.new
object.hello