class Fixnum
  define_method(:leap_year?) do
    self.%(4).eql?(0)
  end
end