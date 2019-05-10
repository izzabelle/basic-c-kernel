// clear the vga buffer
void k_clear(void) {
	char *vga_ptr = (char *) 0xb8000;
	unsigned int i = 0;
	while (i < (80 * 25 * 2)) {
		vga_ptr[i] = ' ';
		i++;
		vga_ptr[i] = 0x0f;
		i++;
	}
}

// print text to the vga buffer
void k_printf(char *msg, unsigned int line) {
	char *vga_ptr = (char *) 0xb8000;
	unsigned int i = 0;
	i = (line * 80 * 2);

	while (*msg != 0) {
		if (*msg == '\n') {
			line++;
			i=(line * 80 * 2);
			*msg++;
		} else {
			vga_ptr[i]=*msg;
			*msg++;
			i++;
			vga_ptr[i] = 0x0f;
			i++;
		}
	}
}

void kmain(void) {
	k_clear();
	k_printf("hello c kernel!", 0);
	while (1) {
		asm("hlt");
	}
}

int main(void) {
	return 0;
}