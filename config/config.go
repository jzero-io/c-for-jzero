package config

type Config struct {
	App      string    `yaml:"app"`
	Packages []Package `yaml:"packages"`
	Jzero    Jzero     `yaml:"jzero"`
}

type Package struct {
	Name  string   `yaml:"name"`
	Paths []string `yaml:"paths"`
}

type Jzero struct {
	Branch string `yaml:"branch"`
}
