module Cv
	class MatSize
		def to_a
			self.dims.times.reduce(Array.new) do |array, i|
				array << self[i]
			end
		end

		def to_s
			"<#{self.class.name}:[#{self.to_a.join(",")}]>"
		end
	end
end
