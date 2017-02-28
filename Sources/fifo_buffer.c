#include "fifo_buffer.h"
#include "Xbee_Driver.h"

/*
 * initialisation de la structure fifo en initialisant les variables begin et end du fifo à 0 et en purgeant ensuite le fifo
 */
void init_fifo(struct Fifo *fifo)
{
	fifo->begin = 0;
	fifo->end = 0;
	flush_fifo(fifo);
}

/*
 * purger le fifo en mettant à 0 begin et end du fifo
 */
void flush_fifo(struct Fifo *fifo)
{
	fifo->begin = 0;
	fifo->end = 0;
}

/*
 * lecture du buffer (cache) du fifo avec en paramètres le pointeur du fifo et le pointeur du buffer de lecture
 *	si la valeur de fifo_buf->begin est égale à fifo_end, buffer vide
 *	sinon récupére l'élément du buffer à l'index courant
 */
int lire_fifo_buffer(struct Fifo *fifo_buf, uint8_t *buffer_lecture)
{
	if(fifo_buf->begin == fifo_buf->end)
	{
		// buffer empty
		*buffer_lecture = 0;
		return -1; //
	}
	else
	{
		// Get buffer element at current index
		*buffer_lecture = fifo_buf->data[fifo_buf->begin];

		fifo_buf->begin++; // Shift index

		if(fifo_buf->begin == FIFO_SIZE)
			fifo_buf->begin = 0;

		return 0;
	}
}



